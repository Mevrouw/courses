<?php

    // configuration
    require("../includes/config.php"); 
    
    //SQL query (returns all rows with users hystory)
    $rows = query("SELECT * FROM history WHERE id=?" , $_SESSION["id"]);
    
    //create a new associative array positions
    $positions = [];
    $rowsrev  = array_reverse($rows);
    foreach ($rowsrev as $row)
    {
        $positions[] = [
            "datetime" => $row["datetime"],
            "symbol" => $row["symbol"],
            "shares" => $row["shares"],
            "buysell" => $row["buysell"],
            "price" => $row["price"] 
            ];
    }
    
    //render history table
    render("history_table.php", ["positions" => $positions, "title" => "History"]);
?>
