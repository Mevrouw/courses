<?php
    
    // configuration
    require("../includes/config.php"); 
    
 
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // lookup stock price
        $stock = lookup($_POST["symbol"]);
        
        //check if symbol is valid
        if ($stock == false)
        {
            apologize("Please provide a valid symbol");
            
        }
        
        // redirect to portfolio
        render("quote.php", ["title" => "Quote price", "stock" => $stock ]);
    }
    else
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }

    
    
?>                                                                                             
