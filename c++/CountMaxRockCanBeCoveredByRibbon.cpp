/*
 * Complete the function below.
 */
int count_rocks(float ribbon_length, vector < vector < float > > rocks) {
     int number = 0;
     int nPeri = 0;
     float nStartX = 0;
     float nStartY = 0;
    
     float nLastX = 0;
     float nLastY = 0;
     all_of(rocks.begin(), rocks.end(), [&number,&nPeri,&nLastX,&nLastY,&nStartX,&nStartY,&ribbon_length](std::vector<float> &vec) {
         if(number==0){
             nStartX = vec[0];
             nStartY = vec[1];
         }else{
             nPeri+= sqrt( ((nLastY-vec[1])*(nLastY-vec[1]))  +  ((nLastX-vec[0])*(nLastX-vec[0])) ) ;
             
             if(nPeri+ sqrt( ((nStartY-vec[1])*(nStartY-vec[1]))  +  ((nStartX-vec[0])*(nStartX-vec[0])) )  > ribbon_length){
                 return false;
             }
             nLastX = vec[0];
             nLastY = vec[1];
         }
         
         number++;
         return true;
    });
    
    return number;
}

