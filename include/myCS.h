#define true 1

#define false 0

typedef char *string;

int println(const string format, ...);

string get_string(const string prompt, int buffer_size);

char get_char(const string prompt);

int get_int(const string prompt, int buffer_size);

int str_to_int(const string str);

long get_long(const string prompt, int buffer_size);

long str_to_long(const string str);

long long get_long_long(const string prompt, int buffer_size);

long long str_to_long_long(const string str);

float get_float(const string prompt, int buffer_size);

float str_to_float(const string str);

double get_double(const string prompt, int buffer_size);

double str_to_double(const string str);

