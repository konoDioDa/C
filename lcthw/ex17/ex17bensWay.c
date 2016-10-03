#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100
//remember, when initializing new struct instances, use constants

struct Address{
//think of the values in the struct address as the X axis in a table
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database {
//we have 100 rows for our "Y" axis as per [MAX_ROWS]
	struct Address rows[MAX_ROWS];
};

struct Connection {
//[*db] is a single instance of our table formed by [Address] and [Database] structs
	FILE *file;
	struct Database *db;
};

void Database_close(struct Connection *conn);

void die(const char *message, struct Connection *conn) {
//if OS returns an error number, report [message] to stdio with [perror()]
	if (errno) {
		perror(message);
	} else {
//if OS doesn't return an error, but if generic failure hapens, report message straight
		printf("ERROR: %s\n", message);
	}
	Database_close(conn);
}

void Address_print(struct Address *addr) {
//when fed a an instance of the [Address] struct, prints it out nice and lovely
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn) {
// is fed with an instance of the [Connection] struct. Remember, the important element of a 
// [Connection] instance is it's second, [db] value, with a set of values on the X axis from 
// an [Address] struct, and 100 [MAX_ROWS] available rows on the Y axis, via [Database] and 
// beginning at [Address] 

	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc !=1) 
		die("Failed to load database", conn);
//if [rc] has no value, it didn't load
}
	

struct Connection *Database_open(const char *filename, char mode) {
//don't know why [*filename] is a constant... [mode] is read, write or any other file open mode
	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn)
		die("Memory error", conn);

//If I  want [die] to close the connection, how is this function initializing that connection, 
//how does [Database_close] kill that connection, and what does it take to bring that to [die].
//In it's original state, [die] is fead only by a [const char *message] (possibly an OS error 
//number, possibly any other value that is then simply [printf]'d). I would like to
// ==ADD ABILITY TO FEED IT A VALUE *conn== but will it be available at that point. Find out.

	conn->db = malloc(sizeof(struct Database));
	if (!conn)
		die("Memory error", conn);

	if (mode == 'c') {

		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");
		if (conn->file) {
			Database_load(conn);
		}
	}
	if(!conn->file)
		die("Failed to open the file", conn);
	return conn;
//This is potentially interesting...
}


void Database_close(struct Connection *conn) {
	if (conn) {
		fclose(conn->file);
	if (conn->db);
		free(conn->db);
	free(conn);
	}
}

void Database_write(struct Connection *conn) {

	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	int (rc != 1) {
		die("Failed to write database.", conn);
	}
	rc = fflush(conn->file);
	if (rc == -1) {
		die("Cannot flush database.", conn);
	}
}

void Database_create(struct Connection *conn) {
	int i = 0;
	for (i = 0; i < MAX_ROWS; i++) {
		// make a prototype to initialize it
		struct Address addr = { .id = i, .set = 0};
	
		//then just assign it
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) {

	struct Address *addr = &conn->db->rows[id];
	if (addr->set) {
		die("Already set, delete it first", conn);
	}
	addr->set = 1;
	//warning: bug, read the "How to break it" and fix this
	char *res = strncpy(addr->name, name, MAX_DATA);
	//demonstrate the strncpy bug
	if (!res) {
		die("Name copy failed", conn);
	}
	res = strncpy(addr->email, email, MAX_DATA);
	if (!res) {
		die("Email copy failed", conn);
	}
}

void Database_delete(struct Connection *conn, int id) {
	struct Address addr = { .id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn) {
	int i = 0;
	struct Database *db = conn->db;
	for (i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];
		if (cur->set){
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[]) {

	if (argc < 3) {
		die("USAGE: ex17 <dbfile> <action> [action params]", NULL);
	}
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if (argc > 3) {
		id = atoi(argv[3]);
	}
	if (id >= MAX_ROWS) {
		die("There's not that many records", NULL);
	}

	switch (action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if (argc != 4) {
				die("Need an ide to get", NULL);
			}
		case 's':
			if (argc != 6){
				die("Need iD, name and email to set", NULL);
			}
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;
		case 'd':
			if (argc != 4) {
				die("Need ID to delete", NULL);
			}
			Database_delete(conn, id);
			Database_write(conn);
			break;
		default:
			die("Invalid action, only: c=create, g=get, s=set, d=del, l=list", NULL);
	}
	Database_close(conn);
	return 0;
}
