cd Cards
call BuildAll.bat

cd ../PlayCards
call BuildAll.bat

cd ..
cl CatchAll.cpp /clr
cl CatchException.cpp /clr:safe
cl Defined.cpp /clr:safe
cl Delegates.cpp /clr:safe
cl Events.cpp /clr:safe
cl Finally.cpp /clr:safe
cl Generics.cpp /clr:safe
cl MultiException.cpp /clr:safe
cl RethrowException.cpp /clr:safe
cl Templates.cpp /clr:safe
cl ThrowDerived.cpp /clr:safe
