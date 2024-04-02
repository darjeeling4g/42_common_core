#!/bin/sh

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
ln -s /usr/bin/php82 /usr/bin/php
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

wp cli update
wp core download --path=/var/www/html --locale=ko_KR

sed -i "s/username_here/$DB_USER/g" /var/www/html/wp-config-sample.php
sed -i "s/password_here/$DB_PASSWORD/g" /var/www/html/wp-config-sample.php
sed -i "s/localhost/$DB_HOST/g" /var/www/html/wp-config-sample.php
sed -i "s/database_name_here/$DB_NAME/g" /var/www/html/wp-config-sample.php
mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

wp core install --path=/var/www/html --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email
wp user create $WP_USER $WP_EMAIL --path=/var/www/html --role=author --user_pass=$WP_PASSWORD

sed -i "s/listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/" /etc/php82/php-fpm.d/www.conf

exec "$@"
