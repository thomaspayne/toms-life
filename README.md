toms-life
===

it's not very interesting
---

A small program to simulate [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life)

It performs the following steps every iteration:

- read from the back buffer
- perform some game logic
- write the result to the back buffer
- swap back and front buffer
- print data to screen

Sample output after 100 iterations:

    --------------------------------------------------
                                                      
                                                      
                     #                                
                   # ##      #                        
                   # #      ##                        
                           #                          
                            ###  #                    
                   # #       ####                     
                  #    #       ##                     
                  #   ##                  ##          
                  # ###          #  #    ####   #     
                                #     ###   ##  ##    
                         ##     #     #### #    ##    
                         # #     # ##    #      ##    
                          #      #             # #    
                  ##                                  
                 #  #                           ##    
                 #  #                                 
                  ##       ##    ##                   
                           ##   #  #                  
                                 ##                   
                                                      
                                                      
                                                      
                                                      
    --------------------------------------------------
    