#include <iostream>
#include <string>

using namespace std;

class ListItem {
  
  private:

    const char* item;
    ListItem* next = nullptr;
    
  public:
    
    ListItem(const char *newItem) {
      item = newItem;
      next = nullptr;
    }

    ListItem* nextItem() {
      return next;
    }

    void setNextItem(ListItem* new_next) {
      next = new_next;
    }

    const char* view() {
      return item;
    }

};

class LinkedList {

  private:

    ListItem* first_item;
    int list_length;
    int counter = 0;
  
    void deleteItem(ListItem* parent, ListItem* item) {
      parent->setNextItem(item->nextItem());
      delete item;
    }

  public:

    LinkedList(const char *newItem) {
      first_item = new ListItem(newItem);
      list_length = 1;
    }

    void addListItem(const char *newItem) {
      ListItem* new_item = new ListItem(newItem);
      ListItem* current_item = first_item;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        current_item=next_item;
        next_item = current_item->nextItem();
      }
      current_item->setNextItem(new_item);
      list_length += 1;
    }

    // my added method to delete an item at a certain position
    void deleteAtPosition(int position) {
        counter = 0;
        position = position - 2;
        ListItem* last_item = first_item;
        ListItem* current_item = first_item->nextItem();
        while (current_item != nullptr) {
            if (position == -1) {
                position = position + 2;
                std::cout << "Deleting: " << first_item->view() << " At position " << position << std::endl;
                break;
            }
            else if (counter == position) {
                position = position + 2;
                std::cout << "Deleting: " << current_item->view() << " At position " << position << std::endl;
                break;
            }
            else {
                last_item = current_item;
                current_item = current_item->nextItem();
            }
            counter++;
        }
        last_item = current_item->nextItem();
        delete current_item;
    }
    
    // my added method to display an item at a certain position
    void itemAtPoition(int position) {
        counter = 0;
        position = position - 2;
        ListItem* next_item = first_item->nextItem();
        if (position == -1) {
            position = position + 2;
            std::cout << "Dispaying: " << first_item->view() << " At position " << position << std::endl;
        } else {
            while (next_item != nullptr) {
                if (position == counter) {
                    position = position + 2;
                    std::cout << "Dispaying: " << next_item->view() << " At position " << position << std::endl;
                    break;
                }
                next_item = next_item->nextItem();
                counter++;  
            }
        }
    }

    int length() {
      return list_length;
    }

    void outputLength() {
      std::cout << length() << std::endl;
    }

    void outputList() {
      std::cout << first_item->view() << std::endl;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        std::cout << next_item->view() << std::endl;
        next_item = next_item->nextItem();
      }
    }

    void space() {
        std::cout << "" << std::endl;
    }

};

int main() {
  LinkedList l("sam");
  l.addListItem("bob");
  l.addListItem("mike");
  l.addListItem("luke");
  l.addListItem("jimbo");
  l.addListItem("jack");
  l.outputList();
  l.outputLength();
  l.space();
  l.space();

  // my added features
  l.itemAtPoition(3);
  l.space();
  l.deleteAtPosition(5);
  l.space();
}