#include <dlfcn.h>
#include <assert.h>

int main (void) {
  void *handle;
  void (*test_badger)(void);

  handle = dlopen("./target/debug/libbadger.so", RTLD_LAZY);
  assert (handle);

  *(void**)(&test_badger) = dlsym(handle, "test_badger");
  assert (test_badger);

  test_badger ();
  dlclose(handle);

  return 0;
}
