all:
	@docker compose -f ./srcs/docker-compose.yml up -d

clean:
	@docker compose -f ./srcs/docker-compose.yml down
	
fclean:
	@make clean
	@docker image rm $$(docker image ls -qa)
	@docker volume rm $$(docker volume ls -q)
	@docker builder prune -f

re:
	@make fclean
	@make all
