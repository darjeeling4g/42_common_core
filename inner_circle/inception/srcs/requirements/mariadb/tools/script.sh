#!/bin/sh

sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf
sed -i 's/^\(skip-networking\)/#\1/g' /etc/my.cnf.d/mariadb-server.cnf

openrc
touch /run/openrc/softlevel
rc-service mariadb setup
rc-service mariadb start
mysql -e "CREATE DATABASE $DB_NAME; CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD'; GRANT ALL ON $DB_NAME.* TO 'siyang'@'%'; FLUSH PRIVILEGES;"
rc-service mariadb stop

exec "$@"
