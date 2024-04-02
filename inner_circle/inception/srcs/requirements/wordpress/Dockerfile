FROM alpine:3.18

RUN apk update && \
	apk upgrade && \
	apk add --no-cache wget php82 php82-fpm php82-phar php82-curl php82-mysqli php82-mbstring

COPY ./tools/script.sh /

RUN chmod +x /script.sh

ENTRYPOINT [ "/script.sh" ]

CMD [ "/usr/sbin/php-fpm82" , "-F" ]
