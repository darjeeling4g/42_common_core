#!/bin/sh

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt -subj "/C=KO/ST=Seoul/L=Gangnam-gu/O=42 seoul/OU=siyang/CN=siyang.42.fr/"

exec "$@"
