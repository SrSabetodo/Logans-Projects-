let rec summer (x : int list) : int =  
	match x with 
	| []    -> 0
	| x::xs -> x + summer xs

let rec odd_summer (x : int list) : int = 
	match x with 
	| [] -> 0
	| x::xs -> if x mod 2 == 0 then x + odd_summer xs else odd_summer xs 

let rec better_odd_summer (x : int list) : int = 
	let is_even (x : int) : bool = 
		if x mod 2 == 0 then true else false 
	in
	match x with 
	| []    -> 0 
	| x::xs -> if is_even x then x + better_odd_summer xs else better_odd_summer xs

let factor (x : int) : int =
	let rec factor_helper ((num : int) ,(accum : int)) : int =
		if accum <> 0 then (num) * factor_helper(num-1,accum-1) else 1 
	in 
	factor_helper(x,x)

(* Assume that y is bigger than x, sum all nums from x to y *)
let rec prob (x : int) (y : int) : int = 
	if (y+1) > x then x + (prob (x+1) y) else 0  	

(* Assume that y is bigger than x, sum all odd nums from x to y *)
let rec prob_odd (x : int) (y : int) : int = 
	if (y+1) > x then 
		if x mod 2 <> 0 then 
			x + (prob_odd (x+1) y) 
		else 
			(prob_odd (x + 1) y)
	else 0 

(* 1 3 5 *)

(* Find min of a list *)
let min_list (lst : int list) : int = 
	let rec min_list_helper (lster : int list) (min : int) : int = 
		match lster with 
		| [] -> -1
		| x::[] -> min 
		| x::xs -> if min > x then min_list_helper xs x else min_list_helper xs min 
	in 
	min_list_helper lst (List.hd lst)

(* Drop num amount of elements from list *)
let rec drop (num : int) (lst : 'a list) : 'a list = 
	if num == 0 then lst 
	else 
		( match lst with
		| [] -> []  
		| x::xs -> drop (num-1) xs ) 