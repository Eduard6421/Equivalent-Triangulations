# Equivalent Triangulations


# Software that transforms one triangulation of a set of points into another triangulation.

# Input method :

1) The input should contain the number of triangles of the first triangulation : n ;
2) The software expects then the edges of the triangles;
3) Repeat for the second triangulation;

! The &var test =   and the & at the end of the input must be found at all times because it's the way the visual software parses the input !

# Ideea :
  1) Transform T1 into the optimal angle triangulation(D) of the set of points;
  2) Transform T2 into the optimal angle triangulation(D) of the set of points;
  3) The flip succesions from T1 to D and the reverse of T2 do D gives the complete path of T1 to T2; ( T1->D->T2);

# What the algorithm actually does :

  Given a triangulation T1, the software uses FLIP type operations to transform the non-delaunay triangles into delaunay ones.
  We do the same procedures for the triangulation T2;
    
  In the case that 2 triangles with a common edge are both delaunay,the software forces the common edge to make an angle of (0,90] degress with the OX axis. This happens because one set of points might have multiple optimal angle triangulations and we wish to find the same one for both T1 and T2.


  Software was written using C++ / Javascript ( for visuals)
