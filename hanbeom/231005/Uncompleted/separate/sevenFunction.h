#ifndef SEVENFUNCTION_H
#define SEVENFUNCTION_H

int addClient(struct Client* client, int k);
int addMonths(char* name_func2, int months_func2, struct Client* client, int k);
int handover(char* name_giver, char* name_receiver, struct Client *client, int k);
int deleteClient(char* name_delete, struct Client *client, int k);
int searchClient(char* name_search, struct Client *client, int k);
int searchList(struct Client *client, int k);
int updateDays(struct Client *client, int k);

#endif
