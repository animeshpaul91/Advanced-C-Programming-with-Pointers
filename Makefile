.PHONY: clean All

All:
	@echo "----------Building project:[ FunctionPointerArray - Debug ]----------"
	@cd "FunctionPointerArray" && "$(MAKE)" -f  "FunctionPointerArray.mk"
clean:
	@echo "----------Cleaning project:[ FunctionPointerArray - Debug ]----------"
	@cd "FunctionPointerArray" && "$(MAKE)" -f  "FunctionPointerArray.mk" clean
