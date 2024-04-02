FROM alpine:3.18

RUN apk update && \
	apk upgrade && \
	apk add --no-cache nginx openssl

COPY ./conf/default.conf /etc/nginx/http.d/default.conf
COPY ./tools/script.sh /

RUN chmod +x /script.sh

ENTRYPOINT [ "/script.sh" ]

CMD [ "nginx" , "-g" , "daemon off;" ]
