<?php

    // configuration
    require("../includes/config.php"); 
    
    //in case form is submitted:
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]))
        {
            apologize("Please pick a symbol to sell");
        }
        
        // find the (user owned!) stock the user wants to sell. (returns ROW with id, symbol, shares)
        $rowToSell = query("SELECT * from portfolio WHERE id = ? AND symbol = ?" ,$_SESSION["id"],$_POST["symbol"]);
        
        // lookup stock-info (returns: symbol, name, price)
        $stockinfo = lookup ($_POST["symbol"]);
        
        // delete stock
        $query = query ("DELETE from portfolio WHERE id = ? AND symbol = ?" ,$_SESSION["id"],$_POST["symbol"]);
        
        // calculate total prize (prize * shares)
        $value = ($stockinfo["price"] * $rowToSell[0]["shares"]);
        
        // update cash
        $query = query( "UPDATE users SET cash = cash + ? WHERE id = ?" , $value, $_SESSION ["id"] ); 
        
        //add transaction to history
        $query = query("INSERT INTO history (id, symbol, shares, buysell, price) VALUES (?, ?, ?, ?, ?)", 
        $_SESSION["id"], $stockinfo["symbol"], $rowToSell[0]["shares"], "SELL", $value ); 
        
        if ($query === false)
        {
            apologize("Something went wrong!History could not be updated.");
        }
        
        
        redirect("/");

    }
    
   
    
    else
    {
        // Create an array of user owned shares-symbols
        $sharesymbols = query("SELECT symbol FROM portfolio WHERE id = ?", $_SESSION["id"]);
        render("sell_form.php", ["title" => "Sell", "symbols" => $sharesymbols]);
    }       
?>
