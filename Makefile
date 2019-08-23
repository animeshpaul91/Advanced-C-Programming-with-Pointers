.PHONY: clean All

All:
	@echo "----------Building project:[ AddAfter - Debug ]----------"
	@cd "AddAfter" && "$(MAKE)" -f  "AddAfter.mk"
clean:
	@echo "----------Cleaning project:[ AddAfter - Debug ]----------"
	@cd "AddAfter" && "$(MAKE)" -f  "AddAfter.mk" clean
