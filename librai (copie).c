#include <stdio.h>
#include <mysql/mysql.h>

//Fonction
void role(){
	char role;
	printf("veuillez saisir le role");
	scanf("%c",&role);
	printf("vous avez ajouté le role %c avec succes",role);
}


int main(){
MYSQL *conn;
//MYSQL_RES *res;
//MYSQL_ROW *sow;

 char *server = "localhost";
 char *user = "root";
 char *password = "";
 char *database = "Biblio_bd";

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
	role();
   // Fermer la connexion
  mysql_close(conn);

  return 0;
}
