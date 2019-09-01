.PHONY: clean All

All:
	@echo "----------Building project:[ FromBook - Debug ]----------"
	@cd "FromBook" && "$(MAKE)" -f  "FromBook.mk"
clean:
	@echo "----------Cleaning project:[ FromBook - Debug ]----------"
	@cd "FromBook" && "$(MAKE)" -f  "FromBook.mk" clean
