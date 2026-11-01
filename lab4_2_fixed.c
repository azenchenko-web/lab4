#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[32];
} User;

User* create_user_list(int count) {
    User *users = (User*)malloc(count * sizeof(User));
    if (!users) return NULL;

    for (int i = 0; i < count; i++) {
        users[i].id = i + 1;
        snprintf(users[i].name, sizeof(users[i].name), "User_%d", i + 1);
    }
    return users;
}

void process_users() {
    int count = 5;
    User *users = create_user_list(count);

    if (!users) return;

    printf("Створено користувачів: %d\n", count);
    printf("Перший користувач: ID=%d, Name=%s\n", users[0].id, users[0].name);

    free(users);
    users = NULL;
}

int main() {
    process_users();
    return 0;
}