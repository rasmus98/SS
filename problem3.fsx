[<EntryPoint>]
let main argv = 
    let n = 1000000
    let rate, specificity, sensitivity = (0.01, 0.993, 0.998)
    let rnd = System.Random()
    let population = List.init n (fun _ ->  // list of (allergic, positive)
        (match rnd.NextDouble () < rate with
        | true -> (true, rnd.NextDouble() < sensitivity)
        | _ -> (false, rnd.NextDouble() < 1. - specificity)
        ))
    let probability (list: bool list) = float ((list |> List.filter id).Length)/ float(list.Length)
    printfn "3a:\nP(T=1)=%f\nP(T=-1)=%f\n3b:\nP(A=0|T=1)=%f\n3c:\nP(A=1|T=1)=%f"
        (population |> List.map snd |> probability)
        (population |> List.map (snd >> not) |> probability)
        (population |> List.filter (snd >> not) |> List.map (fst >> not) |> probability)
        (population |> List.filter snd |> List.map fst |> probability)
    0