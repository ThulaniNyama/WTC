//
//  SkillsCellTableViewCell.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

class SkillsCell: UITableViewCell {

    @IBOutlet weak var progressView: UIProgressView!
    
    @IBOutlet weak var valueLabel: UILabel!
    @IBOutlet weak var nameLabel: UILabel!
    
    func initCell(name: String, value: Float) {
        
        nameLabel.text = name

        let val : String = String(value)
        valueLabel.text = "\(val) %"
        
        progressView.progress = value.truncatingRemainder(dividingBy: 1)

    }
}
