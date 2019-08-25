.PHONY: clean All

All:
	@echo "----------Building project:[ DeepShallowCopy - Debug ]----------"
	@cd "DeepShallowCopy" && "$(MAKE)" -f  "DeepShallowCopy.mk"
clean:
	@echo "----------Cleaning project:[ DeepShallowCopy - Debug ]----------"
	@cd "DeepShallowCopy" && "$(MAKE)" -f  "DeepShallowCopy.mk" clean
