.PHONY: clean All

All:
	@echo "----------Building project:[ CommonProblems - Debug ]----------"
	@cd "CommonProblems" && "$(MAKE)" -f  "CommonProblems.mk"
clean:
	@echo "----------Cleaning project:[ CommonProblems - Debug ]----------"
	@cd "CommonProblems" && "$(MAKE)" -f  "CommonProblems.mk" clean
