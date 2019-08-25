.PHONY: clean All

All:
	@echo "----------Building project:[ SimpleFunctionPointer - Debug ]----------"
	@cd "SimpleFunctionPointer" && "$(MAKE)" -f  "SimpleFunctionPointer.mk"
clean:
	@echo "----------Cleaning project:[ SimpleFunctionPointer - Debug ]----------"
	@cd "SimpleFunctionPointer" && "$(MAKE)" -f  "SimpleFunctionPointer.mk" clean
