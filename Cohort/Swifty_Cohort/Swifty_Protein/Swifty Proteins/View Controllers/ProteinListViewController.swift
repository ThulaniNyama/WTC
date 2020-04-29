//
//  ProteinListViewController.swift
//  Swifty Proteins
//
//  Created by Mcebo Xaba on 2019/11/22.
//  Copyright © 2019 mxaba. All rights reserved.
//

import UIKit

class ProteinListViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate {

    var ListOfLigands : [String] = []
    var FilteredLigandsData : [String] = []
    @IBOutlet weak var searchBar: UISearchBar!
    var isSearching : Bool = false
    @IBOutlet weak var tableView: UITableView!
    var LigandStoredForSegue : String = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Ligands"
        // Do any additional setup after loading the view.
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if isSearching {
            return self.FilteredLigandsData.count
        }
        else {
            return self.ListOfLigands.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell : ProteinListTableViewCell = tableView.dequeueReusableCell(withIdentifier: "myCell", for: indexPath) as! ProteinListTableViewCell
        if (isSearching) {
            cell.ligandName.text = self.FilteredLigandsData[indexPath.row]
        }
        else
        {
            cell.ligandName.text = self.ListOfLigands[indexPath.row]
        }
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        if isSearching {
            self.LigandStoredForSegue = self.FilteredLigandsData[indexPath.row]
            performSegue(withIdentifier: "GoTo3DModel", sender: self)
        }
        else {
            self.LigandStoredForSegue = self.ListOfLigands[indexPath.row]
            performSegue(withIdentifier: "GoTo3DModel", sender: self)
        }
    }
    
    func searchBar(_ searchBar: UISearchBar, textDidChange searchText: String)
    {
        if searchText == ""
        {
            self.FilteredLigandsData = self.ListOfLigands
        }
        else
        {
            self.FilteredLigandsData = self.ListOfLigands.filter({$0.contains(searchText) == true})
        }
        self.isSearching = true
        self.tableView.reloadData()
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "GoTo3DModel" {
            if let nextViewController = segue.destination as? LigandModelViewController {
                nextViewController.ligandName = self.LigandStoredForSegue
            }
        }
    }
}
