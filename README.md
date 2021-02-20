# dlopen_live_reload
Demonstration of live reloading libraries in c

**Run**
```bash
make all
 ```

Open a new terminal side by side in the same directory.
Make changes in `src/lib.c`

**Compile it**
```bash
make make_lib
```

Press enter on the first terminal and see the output change before you.
This is just a simple demonstration. You can implement state management with hot reloading using the same idea.
