FROM alpine:3.18

RUN apk update && \
	apk upgrade && \
	apk add --no-cache openrc mariadb mariadb-client

COPY ./tools/script.sh /

RUN chmod +x /script.sh

ENTRYPOINT [ "/script.sh" , "mysqld_safe" ]

# CMD [ "mysqld_safe" ]
