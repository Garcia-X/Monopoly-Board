## Entry 1
**Date:** 2026-02-25  
**Entry Type:** Engineering Decision  
**Task worked on:** Project setup + file organization  
**Issue or decision:** How to split code between .h and .cpp  
**Error message / symptom:** N/A  
**What I tried:** Considered putting everything in one .cpp for simplicity.  
**Fix / resolution:** Put template classes (Node + CircularLinkedList) in the header to avoid template linker issues, and keep MonopolySpace method definitions + main() in the .cpp.  
**Commit(s):** c2b3e77

---

## Entry 2
**Date:** 2026-02-26  
**Entry Type:** Bug Fix  
**Task worked on:** CMake / CLion build configuration  
**Issue or decision:** CLion said the file didn’t belong to a target / CMake couldn’t find main.cpp  
**Error message / symptom:** “Cannot find source file …/main.cpp” and “No SOURCES given to target”  
**What I tried:** Checked project folders and noticed CMake was pointing to the wrong path.  
**Fix / resolution:** Updated CMakeLists.txt to build monopoly_board.cpp. Reloaded CMake and build succeeded.  
**Commit(s):** ef13509

---

## Entry 3
**Date:** 2026-02-27  
**Entry Type:** Edge Case / Testing Entry  
**Task worked on:** Full 40-space board construction using addMany + verifying circular traversal  
**Issue or decision:** Needed to confirm the board never exceeds 40 nodes and traversal wraps correctly.  
**Error message / symptom:** N/A 
**What I tried:** Built a standard 40-space board (Spaces requested: 40) and printed from the player to verify order and wrapping.  
**Fix / resolution:**
- Verified addMany added exactly 40 spaces (Spaces added: 40, Board size: 40).
- Attempted to add a 41st space and confirmed it was rejected and size stayed 40.
- Printed 45 spaces from the player and confirmed wrap-around back to GO without infinite looping.

**Commit(s):** 78a4d18

---

## Entry 4
**Date:** 2026-02-28  
**Entry Type:** Edge Case / Testing Entry  
**Task worked on:** Core C movePlayer traversal + playable turn loop  
**Issue or decision:** Needed to confirm player movement is node-by-node, wraps correctly, and counts passing GO (tail → head).  
**Error message / symptom:** N/A (behavior/testing validation)  
**What I tried:** Built the 40-space board, ran 10 simulated turns with dice rolls (2–12), printed the landed space each turn, and watched the pass GO counter.  
**Fix / resolution:** Confirmed the player lands on the expected spaces after each roll and passGoCount increments when movement crosses from tail to head (observed passGoCount increase during the turn loop).  
**Commit(s):**