.PHONY: clean All

All:
	@echo "----------Building project:[ SearchinginC - Debug ]----------"
	@cd "Google" && "$(MAKE)" -f  "SearchinginC.mk"
clean:
	@echo "----------Cleaning project:[ SearchinginC - Debug ]----------"
	@cd "Google" && "$(MAKE)" -f  "SearchinginC.mk" clean
