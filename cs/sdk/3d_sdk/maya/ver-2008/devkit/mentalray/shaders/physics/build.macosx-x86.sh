g++ -c -O3 -mtune=pentiumpro -fexpensive-optimizations -fforce-mem -finline-functions -funroll-loops -fomit-frame-pointer -frerun-cse-after-loop -fstrength-reduce -fforce-addr -fPIC -std=c++98 -dynamic -fno-common -DQMC -DMI_MODULE= -DMI_PRODUCT_RAY -DMACOSX -D_REENTRANT -DEVIL_ENDIAN -DX86 -DHYPERTHREAD -I.  dgsutil.cpp
g++ -c -O3 -mtune=pentiumpro -fexpensive-optimizations -fforce-mem -finline-functions -funroll-loops -fomit-frame-pointer -frerun-cse-after-loop -fstrength-reduce -fforce-addr -fPIC -std=c++98 -dynamic -fno-common -DQMC -DMI_MODULE= -DMI_PRODUCT_RAY -DMACOSX -D_REENTRANT -DEVIL_ENDIAN -DX86 -DHYPERTHREAD -I.  dgsshade.cpp
g++ -c -O3 -mtune=pentiumpro -fexpensive-optimizations -fforce-mem -finline-functions -funroll-loops -fomit-frame-pointer -frerun-cse-after-loop -fstrength-reduce -fforce-addr -fPIC -std=c++98 -dynamic -fno-common -DQMC -DMI_MODULE= -DMI_PRODUCT_RAY -DMACOSX -D_REENTRANT -DEVIL_ENDIAN -DX86 -DHYPERTHREAD -I.  dielecshade.cpp
g++ -c -O3 -mtune=pentiumpro -fexpensive-optimizations -fforce-mem -finline-functions -funroll-loops -fomit-frame-pointer -frerun-cse-after-loop -fstrength-reduce -fforce-addr -fPIC -std=c++98 -dynamic -fno-common -DQMC -DMI_MODULE= -DMI_PRODUCT_RAY -DMACOSX -D_REENTRANT -DEVIL_ENDIAN -DX86 -DHYPERTHREAD -I.  partishade.cpp
g++ -c -O3 -mtune=pentiumpro -fexpensive-optimizations -fforce-mem -finline-functions -funroll-loops -fomit-frame-pointer -frerun-cse-after-loop -fstrength-reduce -fforce-addr -fPIC -std=c++98 -dynamic -fno-common -DQMC -DMI_MODULE= -DMI_PRODUCT_RAY -DMACOSX -D_REENTRANT -DEVIL_ENDIAN -DX86 -DHYPERTHREAD -I.  pathshade.cpp
g++ -c -O3 -mtune=pentiumpro -fexpensive-optimizations -fforce-mem -finline-functions -funroll-loops -fomit-frame-pointer -frerun-cse-after-loop -fstrength-reduce -fforce-addr -fPIC -std=c++98 -dynamic -fno-common -DQMC -DMI_MODULE= -DMI_PRODUCT_RAY -DMACOSX -D_REENTRANT -DEVIL_ENDIAN -DX86 -DHYPERTHREAD -I.  physlight.cpp
g++ -c -O3 -mtune=pentiumpro -fexpensive-optimizations -fforce-mem -finline-functions -funroll-loops -fomit-frame-pointer -frerun-cse-after-loop -fstrength-reduce -fforce-addr -fPIC -std=c++98 -dynamic -fno-common -DQMC -DMI_MODULE= -DMI_PRODUCT_RAY -DMACOSX -D_REENTRANT -DEVIL_ENDIAN -DX86 -DHYPERTHREAD -I.  physlens.cpp
g++ -flat_namespace -undefined suppress -dynamiclib -o physics.so dgsutil.o dgsshade.o dielecshade.o partishade.o pathshade.o physlight.o physlens.o

