#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include <hiredis.h>
using namespace std;


void rpush( redisContext *c, const string &key, const vector<string> &v )
{
  vector<const char *> argv( v.size() + 2 );
  vector<size_t> argvlen( v.size() + 2 );
  int j = 0;

  static char rpushcmd[] = "RPUSH";
  argvlen[j] = sizeof(rpushcmd)-1;
  ++j;

  argv[j] = key.c_str();
  argvlen[j] = key.size();
  ++j;

  for ( vector<string>::const_iterator i = v.begin(); i != v.end(); ++i, ++j )
    argv[j] = i->c_str(), argvlen[j] = i->size();

  void *r = redisCommandArgv(c, argv.size(), &(argv[0]), &(argvlen[0]) );
  if ( !r )
    throw runtime_error( "Redis error");
  freeReplyObject( r );
}

void do_test( redisContext *c )
{
  const char *param[5] = { "AAAAA", "B", "CCCCCC", "DDD", "EEEEEEEEE" };
  vector<string> v( param, param+5 );

  try
  {
    rpush( c, "mykey", v );
  }
  catch ( runtime_error & )
  {
    cerr << "Error" << endl;
  }
}


int main(int argc, char *argv[] ) {

  redisContext *c;

  c = redisConnect("localhost",6379);
  if (c->err) {
    cerr << "Connection error: " << c->errstr << endl;
    return -1;
  }

  do_test(c);

  redisFree(c);
  return 0;
}
