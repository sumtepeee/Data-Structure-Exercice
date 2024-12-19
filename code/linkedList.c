#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct entry {
    char name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    char phone[MAX_LENGTH];
    struct entry *next;
} Entry;
Entry *head = NULL;

void insert(Entry *new_entry) {
    Entry *current = head;
    
        printf("Yeni kaydın adını giriniz : ");
        scanf("%s",&new_entry->name);
        printf("Yeni kaydın soyadını giriniz : ");
        scanf("%s",&new_entry->surname);
        printf("Yeni kaydın numarasını giriniz : ");
        scanf("%s",&new_entry->phone);

        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_entry;
    
    printf("Yeni kayıt başarıyla eklendi.\n");
}

void create_entry() {
    
    Entry *new = (Entry*)malloc(sizeof(Entry));
    if (new == NULL)
    {
        printf("Entry creation failed\n");
        return;
    }
    else
    {
        if (head == NULL)
        {
            head = new;
        }
        insert(new);
        new->next = NULL;
        
    }
}



void print_it_out() {
    Entry *curr = head;
    while (curr != NULL)
    {
        printf("İsim : %s\t Soyisim : %s\t Numarası : %s\t\n",curr->name,curr->surname,curr->phone);
        curr = curr->next;
    }

}

void delete_something(const char *phone_number) {
    Entry *current = head;
    Entry *prev = NULL;
    int deleted_count = 0;

    while (current != NULL) // strcmp aynıysalar 0 dondurur
    {
      if (!strcmp (phone_number , current->phone) )
      {
        Entry * temp = current;
        if (prev == NULL)
        {
            head = head->next;
            current = head;
            deleted_count++;
        }
        else
        {
            prev->next = current->next;
            deleted_count++;
        }
        free(temp);
      }
      prev = current;
      current = current->next;
    }

    if (deleted_count > 0) {
        printf("%d kayıt başarıyla silindi.\n", deleted_count);
    } else {
        printf("Bu telefon numarasına sahip kayıt bulunamadı.\n");
    }
}

void search_something(const char *phone_number) {
    Entry *current = head;
    int found_count = 0;

    while (current != NULL)
    {
        if (!strcmp(phone_number,current->phone)) // strcmp aynıysalar 0 dondurur
        {
            printf("Bu telefon numarasına ait kayıtlı kişi'nin ;\n   Adı : %s\n   Soyadı : %s\n   Numarası : %s\n\n",current->name,current->surname,current->phone);
            found_count ++;
        }
        current = current->next;
    }
    
    if (found_count == 0) {
        printf("Bu telefon numarasına sahip kayıt bulunamadı.\n");
    } else {
        printf("Toplam %d kayıt bulundu.\n", found_count);
    }
}

int main() {
    int choice;
    char phone_number[MAX_LENGTH];

    while (1) {
        printf("\n1. Yeni kayıt ekle\n");
        printf("2. Tüm kayıtları listele\n");
        printf("3. Kayıt sil\n");
        printf("4. Kayıt ara\n");
        printf("5. Çıkış\n");
        printf("Seçiminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_entry();
                break;
            case 2:
                print_it_out();
                break;
            case 3:
                printf("Silinecek telefon numarası: ");
                scanf("%49s", phone_number);
                delete_something(phone_number);
                break;
            case 4:
                printf("Aranacak telefon numarası: ");
                scanf("%49s", phone_number);
                search_something(phone_number);
                break;
            case 5:
                printf("Program sonlandırılıyor...\n");
                while (head != NULL) {
                    Entry *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}