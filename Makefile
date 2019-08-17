.PHONY: clean All

All:
	@echo "----------Building project:[ AddressArithmetic3 - Debug ]----------"
	@cd "AddressArithmetic3" && "$(MAKE)" -f  "AddressArithmetic3.mk"
clean:
	@echo "----------Cleaning project:[ AddressArithmetic3 - Debug ]----------"
	@cd "AddressArithmetic3" && "$(MAKE)" -f  "AddressArithmetic3.mk" clean
