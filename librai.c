#include <stdio.h>
#include <mysql/mysql.h>
#include <stdlib.h>
#include <string.h>

//Fonction
void addRole(MYSQL *conn){
	char query[200];
	char role[100];
	printf("veuillez saisir le role");
	scanf("%s", role);
	printf("vous avez ajouté le role : ");
	printf("\"%s\"", role);
	sprintf(query, "INSERT INTO roles (nom) VALUES ('%s')", role);
    	if (mysql_query(conn, query)) {
        	fprintf(stderr, "mysql_query() failed: %s\n", mysql_error(conn));
        	return;
    	}
    	printf("Role created successfully.\n");
    }




int main(){
MYSQL *conn;
//MYSQL_RES *res;
//MYSQL_ROW *row;

 char *server = "localhost";
 char *user = "amra";
 char *password = "Detch@22";
 char *database = "biblio_bd";

// Créer un pointeur vers la connexion
        conn = mysql_init(NULL);

// Établir la connexion à la base de données
   if (conn == NULL) {
    printf("Erreur d'initialisation de MySQL : %s\n", mysql_error(conn));
    return 1;
    }
   if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0) == NULL) {
    printf("Erreur de connexion à la base de données : %s\n", mysql_error(conn));
    mysql_close(conn);
    return 1;
  }
	addRole(conn);
   // Fermer la connexion
  mysql_close(conn);

  return 0;
}
