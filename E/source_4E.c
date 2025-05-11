GV *createNode4(char *hoTen, char *hocVi, double soTietDay, double donGia) {
    GV *newGV = (GV*)malloc(sizeof(GV));
    strcpy(newGV->hoTen, hoTen);
    strcpy(newGV->hocVi, hocVi);
    newGV->soTietDay = soTietDay;
    newGV->donGia = donGia;
    newGV->next = NULL;
    return newGV;
}

void insertFirst4(GV **head, GV *newGV) {
    newGV->next = *head;
    *head = newGV;
}

void insertEnd4(GV **head, GV *newGV) {
    if (*head == NULL) {
        *head = newGV;
        return;
    }
    GV *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newGV;
}

GV *nhapGiangVien4() {
    char hoTen[20], hocVi[10];
    double soTietDay, donGia;
    getchar();
    printf("Nhap ho ten: "); scanf("%19s", hoTen);
    printf("Nhap hoc vi: "); scanf("%9s", hocVi);
    printf("Nhap so tiet day: "); scanf("%lf", &soTietDay);
    printf("Nhap don gia: "); scanf("%lf", &donGia);

    return createNode4(hoTen, hocVi, soTietDay, donGia);
}

void inDanhSach4(GV *head) {
    printf("\n---Danh sach giang vien:---\n");
    printf("%-20s %-10s %-15s %-10s\n", "Ho Ten", "Hoc Vi", "So Tiet Day", "Don Gia");
    printf("--------------------------------------------------------------\n");
    GV *current = head;
    while (current != NULL) {
        printf("%-20s %-10s %-15.2lf %-10.2lf\n", 
               current->hoTen, current->hocVi, 
               current->soTietDay, current->donGia);
        current = current->next;
    }
}

void search4(GV *head) {
    printf("\nGiang vien co hoc vi ThS: \n");
    printf("%-20s %-10s %-15s %-10s\n", "Ho Ten", "Hoc Vi", "So Tiet Day", "Don Gia");
    printf("--------------------------------------------------------------\n");

    GV *current = head;
    int cnt = 0;

    while (current != NULL) {
        if (strcmp(current->hocVi, "ThS") == 0) {
            printf("%-20s %-10s %-15.2lf %-10.2lf\n", 
                   current->hoTen, current->hocVi, 
                   current->soTietDay, current->donGia);
            cnt = 1;
        }
        current = current->next;
    }

    if (!cnt) {
        printf("Khong tim thay giang vien co hoc vi ThS\n");
    }
}

double heSo4(char *hocVi) {
    if (strcmp(hocVi, "TS") == 0) return 1.5;
    if (strcmp(hocVi, "ThS") == 0) return 1.0;
    return 0.5;
}

void tinhTien4(GV *head) {
    printf("\nTien giang day:\n");
    printf("%-20s %-10s %-15s\n", "Ho Ten", "He So", "Thanh Tien");
    printf("--------------------------------------\n");

    GV *current = head;
    while (current != NULL) {
        double hesoGV = heSo4(current->hocVi);
        double tien = current->soTietDay * current->donGia * hesoGV;
        printf("%-20s %-10.1lf %-15.2lf\n", 
               current->hoTen, hesoGV, tien);
        current = current->next;
    }
}

void sortSoTietDay4(GV **head) {
    if (*head == NULL || (*head)->next == NULL) return;

    GV *sorted = NULL;
    GV *current = *head;

    while (current != NULL) {
        GV *next = current->next;
        if (sorted == NULL || current->soTietDay > sorted->soTietDay) {
            current->next = sorted;
            sorted = current;
        } else {
            GV *temp = sorted;
            while (temp->next != NULL && temp->next->soTietDay >= current->soTietDay) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

void freeList4(GV **head) {
    GV *current = *head;
    while (current != NULL) {
        GV *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
