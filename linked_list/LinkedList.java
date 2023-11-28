public class LinkedList {
    Node head;

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            next = null;
        };
    }

    public static LinkedList insertAtFirstPosition(LinkedList list, int data) {
        Node newNode = new Node(data);

        if (list.head == null) {
            list.head = newNode;
        } else {
            newNode.next = list.head;
            list.head = newNode;
        }

        return list;
    }

    public static LinkedList insertAtLastPosition(LinkedList list, int data) {
        Node newNode = new Node(data);
        newNode.next = null;

        // When the linked list is empty, the newNode will be the head
        if (list.head == null) {
            list.head = newNode;
        } else {
            // Else traverse till the last currentNode
            // and insertAtLastPosition the new_node there
            Node last = list.head;
            while (last.next != null) {
                last = last.next;
            }

            // Insert the new_node at last currentNode
            last.next = newNode;
        }

        return list;
    }

    public static LinkedList deleteByValue(LinkedList list, int value) {
        // 1. check whether the value contains on the head node if yes, perform
        // accordingly
        // 2. Or else if it contains in the middle or last of the linked list
        // 3. It may not present or null

        Node currentNode = list.head, prev = null;

        if (currentNode != null && currentNode.data == value) {
            list.head = currentNode.next;

            System.out.println("\n" + value + " found and deleted successfully...");

            return list;
        }

        while (currentNode != null && currentNode.data != value) {
            prev = currentNode;
            currentNode = currentNode.next;
        }

        if (currentNode != null) {
            prev.next = currentNode.next;

            System.out.println("\n" + value + " found and deleted successfully...");
        }

        if (currentNode == null)
            System.out.println("\n" + value + " not found!...");

        return list;
    }

    public static LinkedList deleteAtPosition(LinkedList list, int position) {
        // Case 1: The position is 0, i.e. the head is to be deleted
        // Case 2: The position is greater than 0 but less than the size of the list,
        // i.e. in the middle or last, except at head
        // Case 3: The position is greater than the size of the list, i.e. position not
        // found in the list

        Node currentNode = list.head, prev = null;

        // Case 1
        if (currentNode != null && position == 0) {
            list.head = currentNode.next;

            System.out.println("\n" + position + " found and deleted successfully...");

            return list;
        }

        // Case 2
        int counter = 0;

        while (currentNode != null) {
            if (currentNode != null && position == counter) {
                prev.next = currentNode.next;

                System.out.println("\n" + position + " found and deleted successfully...");

                break;
            } else {
                prev = currentNode;
                currentNode = currentNode.next;
                counter++;
            }
        }

        // Case 3
        if (currentNode == null) {
            System.out.println("\n" + position + " element not found!...");
        }
        return list;
    }

    public static boolean isEmpty(LinkedList list) {
        if (list.head == null) {
            return true;
        }
        return false;
    }

    public static int size(LinkedList list) {
        int size = 0;
        Node currentNode = list.head;

        if (currentNode != null) {
            while (currentNode != null) {
                currentNode = currentNode.next;
                size++;
            }
        }

        return size;
    }

    public static void removeAllItems(LinkedList list) {
        list.head = null;
    }

    public static void printLinkedList(LinkedList list) {
        if (list.head == null) {
            System.out.println("List is empty");
            return;
        }

        Node currentNode = list.head;

        System.out.println("\nLinked List is: ");
        while (currentNode != null) {
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.next;
        }
        System.out.print(" null");
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        //
        // ******INSERTION******
        //

        System.out.println(isEmpty(list));
        // Insert the values
        list = insertAtLastPosition(list, 1);
        list = insertAtLastPosition(list, 2);
        list = insertAtLastPosition(list, 3);
        list = insertAtLastPosition(list, 4);
        list = insertAtLastPosition(list, 5);
        list = insertAtLastPosition(list, 6);
        list = insertAtLastPosition(list, 7);
        list = insertAtLastPosition(list, 8);

        //
        // ******DELETION AT POSITION******
        //

        System.out.println("Size: " + size(list));
        // Delete node at position 0
        // In this case the key is ***at head***
        deleteAtPosition(list, 0);

        // Print the LinkedList
        printLinkedList(list);
        System.out.println("Size: " + size(list));

        // Delete node at position 2
        // In this case the key is present ***in the
        // middle***
        deleteAtPosition(list, 2);

        // Print the LinkedList
        printLinkedList(list);

        // Delete node at position 10
        // In this case the key is ***not present***
        deleteAtPosition(list, 10);

        removeAllItems(list);

        // Print the LinkedList
        printLinkedList(list);

        System.out.println(isEmpty(list));

        //
        // ******DELETION BY KEY******
        //

        // Delete node with value 1
        // In this case the key is ***at head***
        // deleteByValue(list, 1);

        // // Print the LinkedList
        // printLinkedList(list);

        // // Delete node with value 4
        // // In this case the key is present ***in the
        // // middle***
        // deleteByValue(list, 4);

        // // Print the LinkedList
        // printLinkedList(list);

        // // Delete node with value 10
        // // In this case the key is ***not present***
        // deleteByValue(list, 10);

        // // Print the LinkedList
        // printLinkedList(list);
    }
}