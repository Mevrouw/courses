<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];
 
    // search database for places matching $_GET["geo"] (returns lines
    
    // look into $_GET['geo'] to see whether there is a 2 letter item in there, add a condition to my SQL that the state had to match that (AND)
    // count items in array


    $state = "none";
 
    $rows = query ("SELECT * FROM places WHERE MATCH (
                        postal_code,
                        place_name,
                        admin_name1,
                        admin_name2) 
                     AGAINST (?)",   
                         $_GET['geo']
                    );
                    
    if ($state = "none" )
       {
           $places = $rows;
       }

    

    

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>
