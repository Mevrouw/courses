<?php

    // configuration
    require("../includes/config.php"); 
    
    //in case form is submitted:
    if ($_SERVER["REQUEST_METHOD"] == "POST");
    {
        if(empty($_POST["symbol"])
        {
            apologize("Please pick a symbol to sell");
        }
        
        // find the stock (owned by the user!) the user wants to sell
        $rows = query("SELECT from portfolio WHERE id = ? AND symbol = ?" ,$_SESSION["id"],$_POST["symbol"]);
        
        // lookup stock-info (id, symbol, shares)
        $stock = lookup ($_POST["symbol"]);
        
        // delete stock
        $query = query ("DELETE from portfolio WHERE id = ? AND symbol = ?" ,$_SESSION["id"],$_POST["symbol"]);
        
        // calculate total prize (prize * shares)
        $value = ($stock["price"] * $rows["shares"]);
        
        // TODO update cash
        $query = query( "UPDATE users SET cash = cash + ? WHERE id = ?" , $value, $_SESSION ["id"] ); 

    }
    
    
    
    else
        {
            // Fill the array of user shares
            $rows = query("SELECT symbol FROM portfolio WHERE id = ?", $_SESSION["id"]);
            render("sell_form.php", ["title" => "Buy", "symbols" => $rows]);
        }       
?>
