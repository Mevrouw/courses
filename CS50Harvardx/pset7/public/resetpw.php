<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("resetpw_form.php", ["title" => "Change Password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        // validate submission: al fields filled out?
	    if (empty($_POST["cur_password"]) || empty($_POST["new_password"]) || empty($_POST["confirmation"]))
	    {
	        apologize("All fields are required.");
	    }
	    
        // query database for user (Returns row with id, name, hash)
        $rows = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        
        // if we found user, check password
        if (count($rows) == 1)
        {
            // first (and only) row
            $row = $rows[0];
	    
	        // compare hash of user's input against hash that's in database
            if (crypt($_POST["cur_password"], $row["hash"]) !== $row["hash"])
	        {
	            apologize("Current password is incorrect");
	        }
            // check if new password matches confirmation
            else if ($_POST["new_password"] !== $_POST["confirmation"])
	        {
	            apologize("Passwords do not match.");
	        }
	    }
	    
	    // update password
	    $result = query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["new_password"]), $_SESSION["id"]);
	    
	    if ($result===false)
	    {
	        apologize("Something went wrong");	
	    }
	
	    else 
	    {
	        //redirect("/");
	       // TODO is't better to render a succes page..
	               render("succespw.php", ["title" => "succes!"]);
	    }
	
	
    }

?>


