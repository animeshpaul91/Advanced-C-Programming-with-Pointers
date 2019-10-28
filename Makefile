.PHONY: clean All

All:
	@echo "----------Building project:[ Graph - Debug ]----------"
	@cd "Graph" && "$(MAKE)" -f  "Graph.mk"
clean:
	@echo "----------Cleaning project:[ Graph - Debug ]----------"
	@cd "Graph" && "$(MAKE)" -f  "Graph.mk" clean
