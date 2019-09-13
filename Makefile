.PHONY: clean All

All:
	@echo "----------Building project:[ Custom_Header_File - Debug ]----------"
	@cd "Custom_Header_File" && "$(MAKE)" -f  "Custom_Header_File.mk"
clean:
	@echo "----------Cleaning project:[ Custom_Header_File - Debug ]----------"
	@cd "Custom_Header_File" && "$(MAKE)" -f  "Custom_Header_File.mk" clean
