//
//  ProjectsCell.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

class ProjectsCell: UITableViewCell {

    @IBOutlet weak var nameLabel: UILabel!
    @IBOutlet weak var markLabel: UILabel!
    
    func initCell(key: Projects) {
        guard let status = key.status else { return }
        
        if status == "finished" {
            nameLabel.text = key.validated! ? "✅ \(key.project?.name ?? "")" :  "❌ \(key.project?.name ?? "")";
            markLabel.text = "\(key.final_mark ?? 0) %"
        } else {
            nameLabel.text = "⏳ \(key.project?.name ?? "")"
            markLabel.text = ""
        }
    }
}

