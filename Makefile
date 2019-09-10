.PHONY: clean All

All:
	@echo "----------Building project:[ Google - Debug ]----------"
	@cd "Google" && "$(MAKE)" -f  "Google.mk"
clean:
	@echo "----------Cleaning project:[ Google - Debug ]----------"
	@cd "Google" && "$(MAKE)" -f  "Google.mk" clean
