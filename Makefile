.PHONY: clean All

All:
	@echo "----------Building project:[ DoublyLinkedList - Debug ]----------"
	@cd "DoubleLinkedList1" && "$(MAKE)" -f  "DoublyLinkedList.mk"
clean:
	@echo "----------Cleaning project:[ DoublyLinkedList - Debug ]----------"
	@cd "DoubleLinkedList1" && "$(MAKE)" -f  "DoublyLinkedList.mk" clean
