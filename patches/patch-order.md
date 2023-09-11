- `dwm-dracula-6.4.diff` should come second last and `dwm-koala-config-6.4.diff` should come last.
- Make sure `dwm-singlemon-6.4.diff` comes before `dwm-attachbottom-6.3.diff`. Note that one hunk from attachbottom will fail. Just ignore this one (no need for manual patching in this case).
Any other failed hunks should be manually patched in.
Once your build is complete, you can run `make clean` to clean up *.rej and *.orig files if you used `dwm-cleanup.diff`.
