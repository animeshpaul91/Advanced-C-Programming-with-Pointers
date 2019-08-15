.PHONY: clean All

All:
	@echo "----------Building project:[ MultipleIndirection - Debug ]----------"
	@cd "MultipleIndirection" && "$(MAKE)" -f  "MultipleIndirection.mk"
clean:
	@echo "----------Cleaning project:[ MultipleIndirection - Debug ]----------"
	@cd "MultipleIndirection" && "$(MAKE)" -f  "MultipleIndirection.mk" clean
