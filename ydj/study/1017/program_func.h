int FileOpen(FILE *fp);
int CountLine(FILE *fp);
int RegistNew(FILE *fp, struct member *new_ptr, int i);
int ExtPeriod(FILE *fp, struct member *new_ptr, int cnt_line);
int HandOverPeriod(FILE *fp, struct member *new_ptr, int cnt_line);
int RemvMember(FILE *fp, struct member *new_ptr, int cnt_line);
int FindMember(FILE *fp, struct member *new_ptr, int cnt_line);
int AllMember(FILE *fp, struct member *new_ptr, int cnt_line);
int RenewMember(FILE *fp, struct member *new_ptr, int cnt_line);
