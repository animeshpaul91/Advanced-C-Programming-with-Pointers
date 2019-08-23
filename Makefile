.PHONY: clean All

All:
	@echo "----------Building project:[ RemoveAt - Debug ]----------"
	@cd "RemoveAt" && "$(MAKE)" -f  "RemoveAt.mk"
clean:
	@echo "----------Cleaning project:[ RemoveAt - Debug ]----------"
	@cd "RemoveAt" && "$(MAKE)" -f  "RemoveAt.mk" clean
