//
// Adaptive Simpson's Rule (Wikipedia Article)
//
dbl adaptiveSimpsons(dbl (*f)(dbl),   // ptr to function
                           dbl a, dbl b,  // interval [a,b]
                           dbl epsilon,  // error tolerance
                           int maxRecursionDepth) {   // recursion cap        
  dbl c = (a + b)/2, h = b - a;                                                                  
  dbl fa = f(a), fb = f(b), fc = f(c);                                                           
  dbl S = (h/6)*(fa + 4*fc + fb);                                                                
  return adaptiveSimpsonsAux(f, a, b, epsilon, S, fa, fb, fc, maxRecursionDepth);                   
}                                                                                                   
 
//
// Recursive auxiliary function for adaptiveSimpsons() function below
//                                                                                                 
dbl adaptiveSimpsonsAux(dbl (*f)(dbl), dbl a, dbl b, dbl epsilon,                 
                         dbl S, dbl fa, dbl fb, dbl fc, int bottom) {                 
  dbl c = (a + b)/2, h = b - a;                                                                  
  dbl d = (a + c)/2, e = (c + b)/2;                                                              
  dbl fd = f(d), fe = f(e);                                                                      
  dbl Sleft = (h/12)*(fa + 4*fd + fc);                                                           
  dbl Sright = (h/12)*(fc + 4*fe + fb);                                                          
  dbl S2 = Sleft + Sright;                                                                       
  if (bottom <= 0 || fabs(S2 - S) <= 15*epsilon)   // magic 15 comes from error analysis                                       
    return S2 + (S2 - S)/15;                                                                        
  return adaptiveSimpsonsAux(f, a, c, epsilon/2, Sleft,  fa, fc, fd, bottom-1) +                    
         adaptiveSimpsonsAux(f, c, b, epsilon/2, Sright, fc, fb, fe, bottom-1);                     
}



int main(){
 float I = adaptiveSimpsons(sin, 0, 2, 0.001, 100);        // compute integral of sin(x)
                                                          // from 0 to 2 and store it in 
                                                          // the new variable I
 printf("I = %lf\n",I); // print the result
 return 0;
}

