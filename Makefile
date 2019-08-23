.PHONY: clean All

All:
	@echo "----------Building project:[ QueueLength - Debug ]----------"
	@cd "QueueLength" && "$(MAKE)" -f  "QueueLength.mk"
clean:
	@echo "----------Cleaning project:[ QueueLength - Debug ]----------"
	@cd "QueueLength" && "$(MAKE)" -f  "QueueLength.mk" clean
