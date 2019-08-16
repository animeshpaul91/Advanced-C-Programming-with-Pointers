.PHONY: clean All

All:
	@echo "----------Building project:[ CommandlineArgs - Debug ]----------"
	@cd "CommandlineArgs" && "$(MAKE)" -f  "CommandlineArgs.mk"
clean:
	@echo "----------Cleaning project:[ CommandlineArgs - Debug ]----------"
	@cd "CommandlineArgs" && "$(MAKE)" -f  "CommandlineArgs.mk" clean
