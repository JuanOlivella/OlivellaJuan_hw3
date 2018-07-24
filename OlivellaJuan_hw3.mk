OlivellaJuan_Resultados_hw3.pdf : OlivellaJuan_Resultados_hw3.tex 3D.pdf plot.pdf inicial.pdf 60.pdf corte.pdf inicial2.pdf 602.pdf corte2.pdf
	pdflatex OlivellaJuan_Resultados_hw3.tex
	xdg-open OlivellaJuan_Resultados_hw3.pdf


3D.pdf plot.pdf inicial.pdf 60.pdf corte.pdf inicial2.pdf 602.pdf corte2.pdf : OlivellaJuan_Plots_hw3.py datos.dat inicial.dat 60.dat corte.dat inicial2.dat 602.dat corte2.dat
	python OlivellaJuan_Plots_hw3.py


datos.dat : datos.exe
	./datos.exe > datos.dat


inicial.dat 60.dat corte.dat inicial2.dat 602.dat corte2.dat: datos1.exe
	./datos1.exe


datos.exe : OlivellaJuan_ODE.cpp
	g++ -std=c++11 OlivellaJuan_ODE.cpp -o datos.exe



datos1.exe : OlivellaJuan_PDE.cpp
	g++ -std=c++11 OlivellaJuan_PDE.cpp -o datos1.exe


